#include <iostream>
#include "../include/ListaCircular.h" 

using namespace std;

// Constructor: Inicia los punteros en nullptr
ListaCircular::ListaCircular() {
    ultimo = nullptr; // CORRECCIÓN: Uso de nullptr en lugar de NULL
    oleadaActual = nullptr;
}

// Destructor: Libera la memoria dinámica al terminar el programa
ListaCircular::~ListaCircular() {
    if (ultimo == nullptr) return;

    NodoOleada* aux = ultimo->siguiente; // Empezamos en el primero
    ultimo->siguiente = nullptr;         // Rompemos el círculo para evitar bucle infinito

    while (aux != nullptr) {
        NodoOleada* aEliminar = aux;
        aux = aux->siguiente;
        delete aEliminar; // Liberamos la RAM ocupada por new
    }
}

// Registro de Oleada: Inserta al final y mantiene la circularidad 
void ListaCircular::registrarOleada(Oleada nuevaOleada) {
    NodoOleada* nuevo = new NodoOleada();
    nuevo->dato = nuevaOleada;

    if (ultimo == nullptr) {
        ultimo = nuevo;
        ultimo->siguiente = ultimo; // Se apunta a sí mismo para ser circular
        oleadaActual = ultimo;      // La primera registrada es la actual
    } else {
        nuevo->siguiente = ultimo->siguiente; // El nuevo apunta al primero
        ultimo->siguiente = nuevo;           // El viejo ultimo apunta al nuevo
        ultimo = nuevo;                      // Actualizamos quien es el ultimo
    }
}

// Avanzar: Devuelve la oleada actual y prepara el puntero para la siguiente
Oleada* ListaCircular::avanzarSiguienteOleada() {
    if (ultimo == nullptr || oleadaActual == nullptr) {
        return nullptr;
    }
    
    // CORRECCIÓN: Guardar primero la oleada actual antes de mover el puntero
    Oleada* oleadaARetornar = &(oleadaActual->dato);
    
    // Avanzar el puntero para el próximo llamado
    oleadaActual = oleadaActual->siguiente;
    
    return oleadaARetornar;
}

// Reiniciar: Vuelve el cursor al inicio de la lista 
void ListaCircular::reiniciarCiclo() {
    if (ultimo != nullptr) {
        oleadaActual = ultimo->siguiente; // El siguiente del último es el primero
    }
}

// Mostrar: Recorre la lista circular una vez e imprime todos los datos
void ListaCircular::mostrarOleadas() {
    if (ultimo == nullptr) {
        cout << "No hay oleadas registradas." << endl;
        return;
    }

    NodoOleada* aux = ultimo->siguiente; // Empezamos por el primero
    do {
        // CORRECCIÓN: Añadidos los atributos faltantes (tipo y velocidad)
        cout << "Oleada ID: " << aux->dato.idOleada 
             << " | Enemigos: " << aux->dato.cantidadEnemigos 
             << " (" << aux->dato.tipoEnemigo << ")"
             << " | Vida: " << aux->dato.vidaBase 
             << " | Vel: " << aux->dato.velocidadBase << endl;

        aux = aux->siguiente;
    } while (aux != ultimo->siguiente); // Para cuando vuelve al inicio
}