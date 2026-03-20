#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>

struct Torre {
    int id;               // [cite: 84]
    std::string nombre;   // [cite: 85]
    std::string tipo;     // [cite: 86]
    int posicion;         // [cite: 87]
    int danio;            // [cite: 88]
    int rango;            // [cite: 89]
    int costo;            // [cite: 90]
};

struct Enemigo {
    int id;               // [cite: 94]
    std::string tipo;     // [cite: 95]
    int vida;             // [cite: 96]
    int velocidad;        // [cite: 97]
    int posicion;         // [cite: 98]
    int recompensa;       // [cite: 99]
};

struct Oleada {
    int idOleada;             // [cite: 103]
    int cantidadEnemigos;     // [cite: 104]
    std::string tipoEnemigo;  // [cite: 105]
    int vidaBase;             // [cite: 105]
    int velocidadBase;        // [cite: 106]
};

#endif