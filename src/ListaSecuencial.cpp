#include "../include/ListaSecuencial.h"
#include <iostream>

// Constructor: Inicializa la variable contadora en 0
ListaSecuencial::ListaSecuencial() {
    cantidadActual = 0;
}

// Método para insertar una torre en el arreglo manual [cite: 48]
void ListaSecuencial::insertarTorre(Torre nuevaTorre) {
    // 1. Validar que no se desborde el arreglo (límite de 100)
    if (cantidadActual >= 100) {
        std::cout << "Error: No se pueden construir más torres. Límite alcanzado.\n";
        return;
    }

    // 2. Validar que el ID sea único para evitar errores al eliminar [cite: 49]
    if (buscarTorre(nuevaTorre.id) != nullptr) {
        std::cout << "Error: Ya existe una torre con el ID " << nuevaTorre.id << ".\n";
        return;
    }

    // 3. Insertar la torre en la posición libre y aumentar el contador
    arregloTorres[cantidadActual] = nuevaTorre;
    cantidadActual++;
    std::cout << "Torre '" << nuevaTorre.nombre << "' construida exitosamente.\n";
}

// Método para eliminar una torre y reacomodar el arreglo [cite: 38]
void ListaSecuencial::eliminarTorre(int id) {
    int posicionEncontrada = -1;

    // 1. Buscar el índice de la torre a eliminar
    for (int i = 0; i < cantidadActual; i++) {
        if (arregloTorres[i].id == id) {
            posicionEncontrada = i;
            break;
        }
    }

    // Si no existe, salimos de la función
    if (posicionEncontrada == -1) {
        std::cout << "Error: No se encontro la torre con ID " << id << ".\n";
        return;
    }

    // 2. Desplazar los elementos hacia la izquierda para reacomodar el arreglo [cite: 38]
    for (int i = posicionEncontrada; i < cantidadActual - 1; i++) {
        arregloTorres[i] = arregloTorres[i + 1];
    }

    // 3. Reducir el contador
    cantidadActual--;
    std::cout << "Torre con ID " << id << " destruida correctamente.\n";
}

// Método para buscar una torre y devolver su puntero
Torre* ListaSecuencial::buscarTorre(int id) {
    for (int i = 0; i < cantidadActual; i++) {
        if (arregloTorres[i].id == id) {
            return &arregloTorres[i];
        }
    }
    return nullptr;
}

// Método para imprimir los datos de todas las torres
void ListaSecuencial::mostrarTorres() {
    if (cantidadActual == 0) {
        std::cout << "No hay torres construidas.\n";
        return;
    }

    std::cout << "\n--- LISTA DE TORRES ---\n";
    for (int i = 0; i < cantidadActual; i++) {
        std::cout << "ID: " << arregloTorres[i].id
                  << " | Nombre: " << arregloTorres[i].nombre
                  << " | Posicion: " << arregloTorres[i].posicion
                  << " | Danio: " << arregloTorres[i].danio
                  << " | Rango: " << arregloTorres[i].rango << "\n";
    }
    std::cout << "-----------------------\n";
}

// Retorna la cantidad de torres actuales
int ListaSecuencial::contarTorresActivas() {
    return cantidadActual;
}