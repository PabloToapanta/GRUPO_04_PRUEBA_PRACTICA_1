#include "../include/ListaDobleEnlazada.h"
#include <iostream>

// TODO (Desarrollador 2): Implementar manejo de punteros dobles [cite: 38, 123]

ListaDobleEnlazada::ListaDobleEnlazada() { primero = nullptr; ultimo = nullptr; }
void ListaDobleEnlazada::insertarFinal(Enemigo nuevoEnemigo) {
    //Procedemos a crear el nodo en un espacio real en memoria para el enemigo
    NodoEnemigo* nuevoNodo = new NodoEnemigo(); 
    nuevoNodo->dato = nuevoEnemigo;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (primero == nullptr)
    {//validacion - si la lista esta vacia, el nuevo nodo es primero y ultimo
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        //Si ya existe un nodo unicamente lo conectamos al final
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        ultimo = nuevoNodo;
    }
    std::cout << "Enemigo " << nuevoEnemigo.tipo << " ha spawneado" << std::endl;
}
void ListaDobleEnlazada::eliminarDestruido(int id) {
    if (primero == nullptr) return; //por si la lista esta vacia

    NodoEnemigo* aux = primero;
    //La estructura while nos permitira buscar el nodo que tiene la ID
    while (aux != nullptr && aux->dato.id != id)
    {
        aux=aux->siguiente;
    }

    if (aux == nullptr) return; //Si el ID no es encontrado, se sale del bucle

    //Procedemos a reajustar los punteros de los nodos vecinos
    if (aux == primero && aux == ultimo)
    { //Por si es el unico nodo en la lista
        primero = nullptr;
        ultimo = nullptr;
    }
    else if (aux == primero)
    { //Por si es el primer nodo en la lista
        primero = primero->siguiente;
        primero->anterior = nullptr;
    }
    else if (aux == ultimo)
    { //Por si es el ultimo nodo en la lista
        ultimo = ultimo->anterior;
        ultimo->siguiente = nullptr;
    }
    else{ //Por si se encuentra en medio de los nodos en la lista
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
    }
    
    delete aux;
    std::cout << "El enemigo con ID " << id << " ha sido eliminado" << std::endl;
}
NodoEnemigo* ListaDobleEnlazada::buscarEnemigo(int id) { 
    NodoEnemigo* aux = primero;
    while (aux != nullptr)
    {
        if (aux->dato.id == id)
        {
            return aux; //retornamos el nodo completo si es encontrado
        }
        aux=aux->siguiente;
    }
    return nullptr; 
}
void ListaDobleEnlazada::recorrerAdelante() {
    if (primero == nullptr)
    {//estructura de validacion para verificar la existencia de nemigos
        std::cout << "\nNo existen en el camino" << std::endl;
        return;
    }

    //Creamos un puntero auxiliar el cual nos ayudara a no perder la referencia del nodo original "primero"
    NodoEnemigo* aux = primero;
    std::cout << "-----Lista de enemigos (Inicio-Fin)-----" << std::endl;
    while (aux != nullptr)
    {//accedemos a los datos del enemigo
        std::cout << "ID: " << aux->dato.id
                  << "\nTipo: " << aux->dato.tipo
                  << "\nVida: " << aux->dato.vida
                  << "\nPosicion: " << aux->dato.posicion << std::endl;
        //Realizamos un salto al siguiente nodo
        aux=aux->siguiente;
    }
        
}
void ListaDobleEnlazada::recorrerAtras() {
    if(ultimo == nullptr)
    {
        std::cout << "\nNo existen enemigos activos" << std::endl;
        return;
    }

    NodoEnemigo* aux = ultimo; //esto indica que empezaremos desde el final
    std::cout << "\n-----Enemigos (Vista desde la base al inicio)-----" << std::endl;
    while (aux != nullptr)
    {
        std::cout << "ID: " << aux->dato.id
                  << "\nTipo: " << aux->dato.tipo
                  << "\nPosicion: " << aux->dato.posicion << std::endl;
        aux=aux->anterior; //Retrocedemos
    }
    
}
void ListaDobleEnlazada::actualizarPosiciones() {
    NodoEnemigo* aux=primero;

    while (aux != nullptr)
    {//posicion += velocidad
        aux->dato.posicion += aux->dato.velocidad;
        
        aux=aux->siguiente;
    }
    
}
ListaDobleEnlazada::~ListaDobleEnlazada(){
    NodoEnemigo* aux = primero;
    while (aux != nullptr)
    {
        NodoEnemigo* aEliminar = aux;
        aux=aux->siguiente;
        delete aEliminar; //se eliminara nodo por nodo
    }
    std::cout <<"Memoria de enemigos liberada existosamente" << std::endl;
}
NodoEnemigo* ListaDobleEnlazada::obtenerPrimero() {
    // Permite que Juego.cpp sepa dónde empieza la lista para recorrerla
    return primero;
}