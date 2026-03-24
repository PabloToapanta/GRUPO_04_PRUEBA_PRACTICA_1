#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>

struct Torre {
    int id;               
    std::string nombre;   
    std::string tipo;     
    int posicion;         
    int danio;            
    int rango;            
    int costo;            
};

struct Enemigo {
    int id;               
    std::string tipo;     
    int vida;             
    int velocidad;        
    int posicion;         
    int recompensa;       
};

struct Oleada {
    int idOleada;             
    int cantidadEnemigos;     
    std::string tipoEnemigo;  
    int vidaBase;             
    int velocidadBase;        
};

#endif